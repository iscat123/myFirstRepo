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
cp liblib_webcalc.so* ../$dirtime/lib/
cp libzcontainer.so* ../$dirtime/lib/
cp libalgebra.so* ../$dirtime/lib/
cp libnas.so* ../$dirtime/lib/
cp libplanning.so* ../$dirtime/lib/
cp libzadapters.so* ../$dirtime/lib/
cp liblib_bizmemdb.so* ../$dirtime/lib/
cp liblib_db.so* ../$dirtime/lib/
cp libwrglib.so* ../$dirtime/lib/
cp liblib_smart_common.so* ../$dirtime/lib/
cp liblib_smart_config.so* ../$dirtime/lib/
cp libcimxml.so* ../$dirtime/lib/
cp libjni_smart_lib.so* ../$dirtime/lib/
cp liblib_dbio* ../$dirtime/lib/
cp libhiredis.* ../$dirtime/lib/
cp librunway* ../$dirtime/lib/
cp libzd5k_json_model.so* ../$dirtime/lib/
cp libzd5memdb.so* ../$dirtime/lib/
cp libzoeslib.so* ../$dirtime/lib/
cp libzdscada.so* ../$dirtime/lib/

cd ../bin/
cp zdomodeling ../$dirtime/bin/
cp zweb_ningbo_svg ../$dirtime/bin/
cp zsampleloadpredictdata ../$dirtime/bin/
cp zshaoxingdeduction ../$dirtime/bin/

cd ../

tar -zcvf nb_$dirtime.tar.gz $dirtime/
rm -rf $dirtime

