#!/usr/bin/perl

use strict;
use File::Path;
use File::Copy;

#############################################################################
## 本程序实现的基本功能就是根据sourceInsight的搜索结果提取文件绝对路径.
## 按照网络上的朋友给的建议和指导完成的. 总的来说, 相对有点耗内存. 
## 目前还有以下几点需要升级整理:
##   1. 舍弃sourceInsight, 直接利用perl来搜索, 然后处理;
##   2. 按照获取的路径, 提取文件并保存到另一个路径下面;
#############################################################################

my $SRC_FILE = ${ARGV[0]};
my $PATH_STR = ${ARGV[1]};

if($PATH_STR eq "")
{
	warn "[warning] path is not assign!\n";
}

my $prev_matched = ""; # 用于记录上一次处理的数据
my $run_total = 0;     # 用于统计处理了多少行
my @temp_array;        # 将匹配结果放到这个临时数组内
my %temp_hash;         # 再通过这个哈希表干掉不连续的重复的内容

open(SRC_HANDLE, "<$SRC_FILE") or die "Can not open $SRC_FILE!!!";
open(DST_HANDLE, ">${SRC_FILE}_out") or die "Can not open ${SRC_FILE}_out!!!";

# 先将搜索结果进行匹配，整理，放到一个数组里面
while(my $line = <SRC_HANDLE>)
{
	$run_total += 1;

	# 根据sourceInsight的搜索结果，主要形式是下面这这两种
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

# 把数组中的内容弄到哈希表里面, 绝对路径名作为键值,
# 那么在下一次碰到有相同键值的时候, 就会被自动替换掉,
# 从而达到过滤重复内容的目的。
$run_total = 0;
foreach my $line (@temp_array)
{
	$run_total += 1;
	$temp_hash{$line} = $run_total;
}

# 至此，就可以将哈希表里面的键值写入到文件中了。
my $output_path = "";
my $file_name = "";
my $command = "";
$run_total = 0;
foreach my $line (keys %temp_hash)
{
	$run_total += 1;
	print "\n[$run_total]\n";
	
	# 1. 记录所有的文件
	$line =~ s/\\/\//g;
	print DST_HANDLE $line;

	# 2. 取出文件的路径, 然后创建目录	
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

	# 3. 去掉行末的回车符
	chomp($line);

	# 4. 复制文件. 不论文件是否存在, 覆盖之
	print "--> copy file: $PATH_STR$line\n";
	copy($PATH_STR.$line, $output_path) or warn "--> copy failed: $!";

	# 5. 利用系统命令打印一个副本
#	$command = "type ".$output_path."\/".$file_name." >".$output_path."\/".$file_name.".pojie";
#	$command =~ s/\//\\/g;
#	print "exec: ".$command."\n";
#	system($command);
#
#	# 6. 删除源文件
#	$command = $output_path."\/".$file_name;
#	$command =~ s/\//\\/g;
#	$command = "del /Q ".$command;
#	print "exec: ".$command."\n";
#	system($command);
}

close SRC_HANDLE;
close DST_HANDLE;

