#!usr/bin/perl

##
## getfile.pl test.SearchResults  F:\test
##
## ��������sourceinsight���������"*.SearchResults"�ļ���ȡĿ���ļ�
##
## sourceinsight���������һ��Ϊ"filename (path) : ..."
## ���"(path)"Ϊ��˵��Ϊfile�ڵ�ǰĿ¼��, �����ʾfile�ڵ�ǰĿ¼�����·����
##
## 2013-07-17, first version.
##

use strict;
use File::Path;
use File::Copy;

my $rsltFile = ${ARGV[0]}; ##sourceInsight����������ļ�
my $workPath = ${ARGV[1]}; ##����ȡ���ļ�ԴĿ¼
my $destPath = ${ARGV[2]}; ##����ļ��Ĵ��Ŀ¼

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
    ##�ɵ�����ġ�\�����ߡ�/��
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

##���ļ����ݽ��ж�ȡ��ƥ�䣬��ÿһ���л�ȡ���ļ�����һ������
my @tempArray;
while($line = <srcHandle>)
{
    if ($line =~ m/^\s*(.*?)\s+\(?(.+?)\)?\s*:.*$/)
    {        
        $count++;

        ##����ֻ�ܱ���Դ�ļ������·���������У�������滹Ҫ�ٴ���һ��
        if ($2 eq "")
        {
            #print "$1\n";
            push(@tempArray, "$1\n");
        }
        else
        {
            ##��ʱ�洢Դ�ļ������·����temp������
            my $temp = "$2/$1";
            
            ##����ļ����д���Ŀ��·��
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
    
    ##�������е��������ɹ�ϣ���ɵ��ظ����ļ�
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
        
        ##�ӹ�ϣ���ж�ȡ�ļ�·�������Ƶ�Ŀ���ļ�����
        foreach $line (keys %tempHash)
        {
            ##�ɵ���β�Ļس����з���
            chomp($line);
            
            ##�����ļ���Դ·�����Ƶ�Ŀ��·���£�line�����������ļ������·��
            if (copy("$workPath/$line", "$destPath/$line"))
            {
                $count ++;
                ##����Ŀ���ļ��ľ���·��
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