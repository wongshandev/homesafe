@echo off
echo 使用“getfile.pl”来提取某个目录下的文件
echo 基于sourceinsight的搜索结果，即“*.SearchResults”文件。
echo 示例：getfile.pl proj.SearchResults F:\MyProj
echo 执行后会在F:\MyProj目录下产生一个__output的文件夹。
echo .
pause

getfile.pl MT6252.SearchResults F:\MsgCmd
pause