#!/usr/bin/perl

use strict;
use File::Path;
use File::Copy;

#############################################################################
## ������ʵ�ֵĻ������ܾ��Ǹ���sourceInsight�����������ȡ�ļ�����·��.
## ���������ϵ����Ѹ��Ľ����ָ����ɵ�. �ܵ���˵, ����е���ڴ�. 
## Ŀǰ�������¼�����Ҫ��������:
##   1. ����sourceInsight, ֱ������perl������, Ȼ����;
##   2. ���ջ�ȡ��·��, ��ȡ�ļ������浽��һ��·������;
#############################################################################

my $SRC_FILE = ${ARGV[0]};
my $PATH_STR = ${ARGV[1]};

if($PATH_STR eq "")
{
	warn "[warning] path is not assign!\n";
}

my $prev_matched = ""; # ���ڼ�¼��һ�δ��������
my $run_total = 0;     # ����ͳ�ƴ����˶�����
my @temp_array;        # ��ƥ�����ŵ������ʱ������
my %temp_hash;         # ��ͨ�������ϣ��ɵ����������ظ�������

open(SRC_HANDLE, "<$SRC_FILE") or die "Can not open $SRC_FILE!!!";
open(DST_HANDLE, ">${SRC_FILE}_out") or die "Can not open ${SRC_FILE}_out!!!";

# �Ƚ������������ƥ�䣬�����ŵ�һ����������
while(my $line = <SRC_HANDLE>)
{
	$run_total += 1;

	# ����sourceInsight�������������Ҫ��ʽ��������������
	# Mmi_default.c (ms_mmi\source\mmi_app\kernel\c):#if defined(ETLAMP_TASK_SUPPORT)
	# Project_sc6800h_sp6804h_240x320.mk:ETLAMP_TASK_SUPPORT = TRUE ### etlamp
	# Getfile.pl (d:\perl\getfile):my $SRC_FILE = ${ARGV[0]};
	$line =~s/\s*//g;
	$line =~ m/^([^:\(-]*)[:\(]([^)]*)([\):]*).*/;

	if($1 ne "" && $prev_matched ne $1)
	{
		$prev_matched = $1;
		if($3 eq "" || $2 eq "")
		{
			push(@temp_array, "$1\n");
		}
		else
		{
			push(@temp_array, "${2}"."\\"."${1}"."\n");
		}
	}
}

# �������е�����Ū����ϣ������, ����·������Ϊ��ֵ,
# ��ô����һ����������ͬ��ֵ��ʱ��, �ͻᱻ�Զ��滻��,
# �Ӷ��ﵽ�����ظ����ݵ�Ŀ�ġ�
$run_total = 0;
foreach my $line (@temp_array)
{
	$run_total += 1;
	$temp_hash{$line} = $run_total;
}

# ���ˣ��Ϳ��Խ���ϣ������ļ�ֵд�뵽�ļ����ˡ�
my $output_path = "";
my $file_name = "";
my $command = "";
$run_total = 0;
foreach my $line (keys %temp_hash)
{
	$run_total += 1;
	print "\n[$run_total]\n";
	
	# 1. ��¼���е��ļ�
	$line =~ s/\\/\//g;
	print DST_HANDLE $line;

	# 2. ȡ���ļ���·��, Ȼ�󴴽�Ŀ¼	
	if($PATH_STR ne "")
	{
		$PATH_STR =~ s/[\\\/]$//g;
		$PATH_STR =~ s/\\/\//g;
		$PATH_STR = $PATH_STR."\/";
		$output_path = $PATH_STR.$1;
	}
	else
	{
		$output_path = $1;
	}
	$line =~ m/(.*)[\/\\](.*)$/;
	$file_name = $2;
	$output_path = $output_path."__output\/".$1;
	print "=> create path: $output_path.\n";
	
	if($output_path ne "" && !-e $output_path)
	{
		File::Path::mkpath($output_path) or warn "Create path: $!";
	}

	# 3. ȥ����ĩ�Ļس���
	chomp($line);

	# 4. �����ļ�. �����ļ��Ƿ����, ����֮
	print "--> copy file: $PATH_STR$line\n";
	copy($PATH_STR.$line, $output_path) or warn "--> copy failed: $!";

	# 5. ����ϵͳ�����ӡһ������
#	$command = "type ".$output_path."\/".$file_name." >".$output_path."\/".$file_name.".pojie";
#	$command =~ s/\//\\/g;
#	print "exec: ".$command."\n";
#	system($command);
#
#	# 6. ɾ��Դ�ļ�
#	$command = $output_path."\/".$file_name;
#	$command =~ s/\//\\/g;
#	$command = "del /Q ".$command;
#	print "exec: ".$command."\n";
#	system($command);
}

close SRC_HANDLE;
close DST_HANDLE;

