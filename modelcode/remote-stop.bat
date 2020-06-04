plink -no-antispoof -pw raspberry pi@192.168.137.174 "sudo pkill -f python2; sudo killall pigpiod"
timeout 5 /nobreak