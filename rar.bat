
@echo off
::���Ĺ��̣���Ҫ�޸�����5������
set pro=NEOTEL52_6432_10A
set user_pro=homesafe
set bin=%pro%_PCB01_gprs_MT6252_S01.MAUI_10A_W11_08_MP_V3.bin
set sct=scat%pro%.txt
set dbg=tst\database_classb\BPLGUInfoCustomAppSrcP_MT6252_S01_MAUI_10A_W11_08_MP_V3

set rexe="C:\Program Files\7-Zip\7z.exe"
set rar=%date:~5,2%%date:~8,2%_%user_pro%_v%time:~0,2%%time:~3,2%.7z
set opath=build\%pro%\

if not exist build\%pro% md \build\%pro% 
if not exist %opath%%bin% echo BIN�ļ�������
if not exist %opath%%sct% echo SCT�ļ�������
if not exist %dbg% echo DBG�ļ�������
call %rexe% a -t7z -mx9 %opath%%rar% %opath%%bin% %opath%%sct% %dbg%

if errorlevel 0 echo ѹ���ɹ�
if errorlevel 1 echo ѹ��ʧ�ܣ����ֶ�ѹ��
::ɾ������
set rexe=
set pro=
set bin=
set sct=
set dbg=
set user_pro=