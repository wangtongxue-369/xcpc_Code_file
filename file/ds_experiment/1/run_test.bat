@echo off
cd /d e:\xcpc_Code_file\file\ds_experiment\1

A.exe > test_output.txt

echo "程序已运行完毕，请查看test_output.txt文件获取结果"
type test_output.txt
pause