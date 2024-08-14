#! /usr/bin/expect -f
spawn sftp d5000@10.136.153.36
expect "d5000@10.136.153.36's password:"
send "Ddzdh@123\n";
expect "sftp>"
send "lcd /root/sftp/push\n";
expect "sftp>"
send "cd /home/szdzyk\n";
expect "sftp>"
send "put $1\n";
expect "sftp>"
send "bye\n";
interact
