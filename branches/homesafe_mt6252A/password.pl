#!usr/bin/perl

##
## 
##
## ������ָ�����ļ���������typeΪ.bin��׺������;
## ���߽�.bin��׺������ȥ��
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
        ##�����ļ�
        open(TOBIN, ">$toBin") or die "can not create file.\n";
        print TOBIN "for /R %%i IN ($line) DO type \"%%i\" > \"%%i.bin\" && del /S /Q \"%%i\"";
        close TOBIN;
        ##ִ������
        my $cmd = "start /wait cmd /c \"$toBin\"";
        system($cmd);
        ##ɾ���ļ�
        unlink $toBin;
    }
    else
    {
        print "You are input nothing!\n";	
    }
}
elsif ($line eq "2")
{
    print "You are choose restore form \".bin\".\n";
    
    my $findBin = "~findBin.bat";
    my $listFile = "~file.lst";
    
    if (-e $listFile)
    {
        unlink $listFile;
    }
    
    if (-e $findBin)
    {
        unlink $findBin;
    }
    
    ##�����ļ�
    open(FINDBIN, ">$findBin") or die "can not create file.\n";
    print FINDBIN "for /R %%i IN (*.bin) DO echo %%i >> $listFile";
    close FINDBIN;
    ##ִ������
    my $cmd = "start /wait cmd /c \"$findBin\"";
    system($cmd);
    ##ɾ���ļ�
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
    unlink $listFile;
}
else
{
    print "You are choose unsupported option!\n";	
}

print "\n----process finish----\n";