@echo off
cd /d e:\xcpc_Code_file\file\ds_experiment\1

echo "测试op5功能 - 城市名称字典序排序AVL树"
echo. > test_dict_result.txt

echo 5 | A.exe >> test_dict_result.txt
echo 6 >> test_dict_result.txt
echo A 3 >> test_dict_result.txt
echo B 6 >> test_dict_result.txt
echo C 9 >> test_dict_result.txt
echo D 2 >> test_dict_result.txt
echo E 8 >> test_dict_result.txt
echo F 1 >> test_dict_result.txt

echo "测试完成，请查看test_dict_result.txt文件以获取结果。"
type test_dict_result.txt | findstr "AVL树"
type test_dict_result.txt | findstr /v "已插入节点" | findstr /v "请输入节点数量" | findstr /v "请依次输入"
pause