#!usr/bin/perl

##
## 
##
## 用来将指定的文件类型名字type为.bin后缀的名字;
## 或者将.bin后缀的名字去掉
##
## 20130717, first version
##

use strict;
use File::Path;
use File::Copy;

print "\n----process begin----\n\n";

print "Please choose:\n [1] Backup to \".bin\"\n [2] restore from \".bin\"\n";
my $line = <STDIN>;
chomp($line);
if ($line eq "1")
{
    print "You are choose backup to \".bin\".\n";
    
    my $toBin = "~toBin.bat";
    
    print "Please input file type. [EXP] *.c *.h *.cpp\n";
    $line = <STDIN>;
    chomp($line);
    if ($line ne "")
    {
        my $outputlistfile = "~toBinFileList.txt";
        
        ##防止bin文件在 "backup from *.bin" 的时候将bin文件的后缀名给搞没了
        if (!($line =~ m/\*.bin/i))
        {
            $line .= " *.bin";	
        }
        	
        ##创建文件
        open(TOBIN, ">$toBin") or die "can not create file.\n";
        unlink $outputlistfile;
        print TOBIN "for /R %%i IN ($line) DO echo %%i >>$outputlistfile && type \"%%i\" > \"%%i.bin\" && del /S /Q \"%%i\"";
        close TOBIN;
        ##执行内容
        
        &print_system_time();
        
        my $cmd = "start /wait cmd /c \"$toBin\"";
        system($cmd);
        ##删除文件
        unlink $toBin;
        
        &print_system_time();
    }
    else
    {
        print "You are input nothing!\n";	
    }
}
elsif ($line eq "2")
{
    print "You are choose restore form \".bin\".\n";
    
    &print_system_time();
    
    my $findBin = "~findBin.bat";
    my $listFile = "~fromBinFileList.txt";
    
    if (-e $listFile)
    {
        unlink $listFile;
    }
    
    if (-e $findBin)
    {
        unlink $findBin;
    }
    
    ##创建文件
    open(FINDBIN, ">$findBin") or die "can not create file.\n";
    print FINDBIN "for /R %%i IN (*.bin) DO echo %%i >> $listFile";
    close FINDBIN;
    ##执行内容
    my $cmd = "start /wait cmd /c \"$findBin\"";
    system($cmd);
    ##删除文件
    unlink $findBin;
    
    ##restore
    open(LFH, "<$listFile") or die "can not open file.\n";
    foreach $line (<LFH>)
    {
        chomp($line);
        if ($line	=~ m/(.*)(.bin)\s*$/)
        {
            if (-e "$1$2")
            {
                rename("$1$2", $1);
            }	
        }
    }
    close LFH;
    #unlink $listFile;
    
    &print_system_time();
}
else
{
    print "You are choose unsupported option!\n";	
}

print "\n----process finish----\n";

system("pause");

sub print_system_time()
{
    my ($sec,$min,$hour,$day,$mon,$year,$wday,$yday,$isdst)=localtime(time);
    
    $day=($day<10)?"0$day":$day;
    $mon=($mon<9)?"0".($mon+1):($mon+1);
    $year+=1900;
    
    print "$year-$mon-$day, $hour:$min:$sec\n";
}