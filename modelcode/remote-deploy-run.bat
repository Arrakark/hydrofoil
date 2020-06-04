plink -no-antispoof -pw raspberry pi@192.168.137.174 "sudo pkill -f python2; sudo rm -fR src/; mkdir src; sudo pigpiod"
pscp -pw raspberry -C -r src\ pi@192.168.137.174:/home/pi/pythondev/src
plink -no-antispoof -pw raspberry pi@192.168.137.174 "cd pythondev/src; sudo nohup python2 main.py > /dev/null & "
timeout 5 /nobreak