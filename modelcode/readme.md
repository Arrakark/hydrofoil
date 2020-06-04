# How to setup RaspeberryPi Zero W to run Python code from VSCode headlessly

**PLEASE NOTE:** Bitbucket removes some line endings in readme.md when displaying it. Clone the repo and see the file and line endings in VSCode rather than in web view on bitbucket.

## Prepare the Pi

### Download Raspberry RASPBIAN STRETCH WITH DESKTOP image
  * https://www.192.168.137.174.org/downloads/raspbian/
  * Use this rather than lite version -- there is lot of stuff preinstalled + we have desktop env when needed. Lite image requires more mad Linux skillz.

### Flash image to SD card with Etcher
  * https://etcher.io/

### Make changes to files on flashed SD card to enable network over USB
  * Add ```dtoverlay=dwc2``` to the end of ```config.txt```
  * Add ```modules-load=dwc2,g_ether``` just after ```rootwait``` in ```cmdline.txt```
  * Create empty file named ```ssh``` in root of the SD card

### Install awfull piece of software called Apple BonJour to your PC
  * https://support.apple.com/kb/DL999?viewlocale=en_US&locale=en_US
  * It says something about working only on Windows 7, but it runs on Windows 10 as well

### Connect Raspberry Pi Zero W to PC over USB
  * Use the port marked USB, not the PWR.

### Configure sharing on your Windows network adapter so Pi can see the Internet
  * Go somewhere around __Control Panel -> Network and Internet -> Network Connections__
  * Double click your default network connection, click __Properties...__, tab __Sharing__

### Connect to Pi with Putty
  * http://www.putty.org/
  * Connect over SSH with connection string ```pi@192.168.137.174.local```
  * Accept certificate
  * Default password is ```raspberry```

### Configure Wi-Fi
  * Shell command (over Putty on Pi):
  ```
  sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
  ```
  * Opens file in nano, add to the end of file:
  ```
  network={
    ssid="MY_NETWORK_NAME"
    psk="MY_NETWORK_PASSWORD"
  }
  ```
  * (Obviously, __MY_NETWORK_NAME__ and __MY_NETWORK_PASSWORD__ is your Wi-Fi network name and password.)
  * __Ctrl+O__ to save, __Ctrl+X__ to exit nano
  * Shell command:
  ```
  sudo wpa_cli reconfigure
  ```
  * Reset the system (might be just me, but the wifi didn't work without that).
  * Get IP address of the Pi on the Wi-Fi, either by checking your home router or by  running shell command on the Pi:
  ```
  ifconfig
  ```

### Create sourcecode directory
  * Shell commands:
  ```
  mkdir pythondev
  chmod 0777 pythondev
  cd pythondev
  pwd
  ```
  * Should create directory ```/home/pi/pythondev```

### Update Pi, install samba, config samba
  * Shell command:
  ```
  sudo apt-get update
  ```
  * Shell command:
  ```
  sudo apt-get install samba samba-common-bin
  ```
  * Shell command:
  ```
  sudo nano /etc/samba/smb.conf
  ```
  * Add to the end of file:
  ```
  [pythonapp]
  path=/home/pi/pythondev
  browsable=yes
  writable=yes
  only guest=no
  create mask=0777
  directory mask=0777
  public=yes
  ```
  * Opening ```\\<raspberry.pi.ip.address>\pythondev``` from Windows File Explorer should work

### Install ptvsd on the Pi to be able debug remotely
  * Shell command
  ```
  sudo pip install ptvsd==3.0.0
  ```
  * We use version 3.0.0 sice there seemed to be some issues with newer versions (which might be fixed now).
  * By default Python 2.7.x should be active, check with shell command
  ```
  python --version
  ```

### Resize your Pi partition to use all available space on SD card
  * Shell command:
  ```
  raspi-config --expand-rootfs
  ```
  * Reboot Pi

## Prepare VSCode

### Install Python extension
  * It is the one named just __Python__

### Setup launch.json
```
{
  "version": "0.2.0",
  "configurations": [
    {
        "name": "Attach (Remote Debug)",
        "type": "python",
        "request": "attach",
        "localRoot": "${workspaceRoot}/src",
        "remoteRoot": "/home/pi/pythondev/src",
        "port": 3000,
        "secret": "my_secret",
        "host": "<raspberry.pi.ip.address>",
        "preLaunchTask": "remote-deploy-debug"
    }
  ]
}
```
(Remember to replace ```<raspberry.pi.ip.address>``` with IP address of your Pi.)

### Setup tasks.json
```
{
    "version": "2.0.0",
    "tasks": [
        {
            "taskName": "remote-deploy-run",
            "command": "${workspaceRoot}/remote-deploy-run.bat",
            "type": "shell",
            "problemMatcher": []
        },
        {
            "taskName": "remote-deploy-debug",
            "command": "${workspaceRoot}/remote-deploy-debug.bat",
            "type": "shell",
            "problemMatcher": []
        },
        {
            "taskName": "remote-stop",
            "command": "${workspaceRoot}/remote-stop.bat",
            "type": "shell",
            "problemMatcher": []
        }

    ]
}
```

### Setup remote control scripts
There are three files created in this project:

  * **remote-deploy-debug.bat** -- uploads files and executes ```main.py``` waiting for debugger to attach. This file is meant to be called by VSCode debugger when debugging is started.
  * **remoter-deploy-run.bat** -- uploads files and runs ```main.py```.
  * **remote-stop.bat** -- stops execution of project by killing python process remotely.

These files are connected to the tasks setup in previous step, so it is possible to execute them from VSCode command pallete.

In all three files you need to replace ```<raspberry.pi.ip.address>``` with IP address of your Pi.

### Add some code to main Python file
Add following to the start of the file which gets executed in ```remote-deploy-debug.bat``` or ```remoter-deploy-run.bat``` (typically ```main.py```):

```
import ptvsd
import sys

sys.stderr = open('../error.log', 'w')
if sys.argv.count > 1 and "debug" in sys.argv:
    ptvsd.enable_attach("my_secret", address = ('0.0.0.0', 3000))
    ptvsd.wait_for_attach()

```

Now you should be ready to remotely deploy and debug your Python code from VSCode on you tiny 192.168.137.174 Zero W. Please remember, that things can get slow, so if there is nothing happening for a while, be patient (it takes up to 30 seconds for my Pi to hit the break point for the first time).
