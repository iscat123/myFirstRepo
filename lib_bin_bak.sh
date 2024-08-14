#! /bin/bash

dirtime=$(date "+%Y%m%d%H%M%S")
if [ -d "$dirtime" ] 
then
  echo "文件夹存在"
  echo "删除已存在文件夹"
  rm -rf $dirtime
  echo "创建新文件夹"
  mkdir $dirtime
else
  echo "创建新文件夹"
  echo $dirtime
  mkdir $dirtime
fi

cd $dirtime
mkdir lib/ bin/

cd ../lib/
cp lib*.so* ../$dirtime/lib/

cd ../bin/
cp web* z* ../$dirtime/bin/

cd ../

tar -zcvf $dirtime.tar.gz $dirtime/
rm -rf $dirtime

