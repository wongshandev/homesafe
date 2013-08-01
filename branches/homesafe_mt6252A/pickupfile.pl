#!usr/bin/perl

##
## getfile.pl test.SearchResults  F:\test
##
## 用来根据sourceinsight的搜索结果"*.SearchResults"文件提取目标文件
##
## sourceinsight的搜索结果一般为"filename (path) : ..."
## 如果"(path)"为空说明为file在当前目录下, 否则表示file在当前目录的相对路径下
##
## 2013-07-17, first version.
##

use strict;
use File::Path;
use File::Copy;

my $rsltFile = ${ARGV[0]}; ##sourceInsight的搜索结果文件
my $workPath = ${ARGV[1]}; ##欲提取的文件源目录
my $destPath = ${ARGV[2]}; ##输出文件的存放目录

if ($rsltFile eq "" || $workPath eq "")
{
    print "\nParameter error!\n[USAGE] $0 souceInsight_SearchResults_file work_path [output_path]\n";
    print "Please enter souceInsight_SearchResults_file:\n";
    $rsltFile = <STDIN>;
    chomp($rsltFile);
    if ($rsltFile eq "")
    {
        die "souceInsight_SearchResults_file can\'t be empty!\n";	
    }
    
    if (!($rsltFile =~ m/^*.SearchResults$/i))
    {
        die "file format error.\n";	
    }
    
    print "Please enter work_path:\n";
    $workPath = <STDIN>;
    chomp($workPath);
    if ($workPath eq "")
    {
        die "workPath can\'t be empty!\n";	
    }
    
    print "Please enter output_path:\n";
    $destPath = <STDIN>;
    chomp($destPath);
}

print "\n----Process begin----\n\n";

$rsltFile =~ s/\\/\//g;
$workPath =~ s/\\/\//g;

if ($destPath eq "")
{
    $destPath = $workPath."/__output";
    print "Output path is \"$destPath\".\n";
}
else
{
    ##干掉后面的“\”或者“/”
    $destPath =~ s/(.*)\s*[\\\/]+\s*$/$1/g;
}

if (!-e $destPath)
{
    File::Path::mkpath($destPath) or die "Can\'t create path: \"$!\".\n";
}

my $listFile = "$destPath/filepath.lst";
print "File list is \"$listFile\".\n";


my $count;
my $line;

open(srcHandle, "<$rsltFile") or die "Can\'t open \"${rsltFile}\".\n";

##将文件内容进行读取，匹配，把每一行中获取的文件放入一个数组
my @tempArray;
while($line = <srcHandle>)
{
    if ($line =~ m/^\s*(.*?)\s+\(?(.+?)\)?\s*:.*$/)
    {        
        $count++;

        ##这里只能保存源文件的相对路径到数组中，否则后面还要再处理一次
        if ($2 eq "")
        {
            #print "$1\n";
            push(@tempArray, "$1\n");
        }
        else
        {
            ##暂时存储源文件的相对路径到temp变量中
            my $temp = "$2/$1";
            
            ##输出文件夹中创建目标路径
            if (!-e "$destPath/$2/")
            {
                File::Path::mkpath("$destPath/$2/") or warn "Create path \"$destPath/$2/\" failed.\n";	
            }
           
            $temp =~ s/\\/\//g;
        	  #print "$temp\n";
            push(@tempArray, "$temp\n");
        }
    }
}
print "Total $count matched.\n";
close srcHandle;


if ($count > 0)
{
    $count = 0;
    
    ##将数组中的内容做成哈希表，干掉重复的文件
    my %tempHash;
    foreach $line (@tempArray)
    {
        $count++;
        $tempHash{$line} = $count;
    }
    print "Total $count prcessed.\n";
    
    if ($count > 0)
    {
        $count = 0;
        
        open(listHandle, ">$listFile") or die "Cant\t create \"${listFile}\".\n";
        
        ##从哈希表中读取文件路径，复制到目标文件夹下
        foreach $line (keys %tempHash)
        {
            ##干掉行尾的回车换行符号
            chomp($line);
            
            ##复制文件从源路径复制到目标路径下，line变量中属于文件的相对路径
            if (copy("$workPath/$line", "$destPath/$line"))
            {
                $count ++;
                ##保存目标文件的绝对路径
                print	listHandle "$destPath/$line\n";
            }
            else
            {
                warn "$!\n";
                warn "   |--$workPath/$line\n";
                warn "   |--$destPath/$line\n";
            }
        }
        
        print "Total $count file(s) copied.\n";
        
        close listHandle;
    }
}

print "\n----Process finish----\n";