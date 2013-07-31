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
        my $outputlistfile = "~toBinFileList.txt";
        
        ##�����ļ�
        open(TOBIN, ">$toBin") or die "can not create file.\n";
        unlink $outputlistfile;
        print TOBIN "for /R %%i IN ($line) DO echo %%i >>$outputlistfile && type \"%%i\" > \"%%i.bin\" && del /S /Q \"%%i\"";
        close TOBIN;
        ##ִ������
        
        &print_system_time();
        
        my $cmd = "start /wait cmd /c \"$toBin\"";
        system($cmd);
        ##ɾ���ļ�
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