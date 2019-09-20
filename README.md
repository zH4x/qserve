# QServe 

## What is QServe?

QServe is a cross-platform CLI tool for quickly setting up a server in any directory, on any port.

**How simple?** Open a terminal, navigate to any directory, and run `qserve`.  On port 80, your machine will be hosting all the files in that directory.

## Building

### Linux:

```sh
git clone https://github.com/coltonon/qserve.git
cd qserve
cmake . && make
```

### Windows:
```sh
git clone https://github.com/coltonon/qserve.git
cd qserve
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\amd64\MSBuild.exe" qserve.sln
```
_For other Visual Studio versions/instalations, open the .sln and compile in the IDE_

If you don't feel like compiling, check out the [releases](https://github.com/coltonon/qserve/releases).

## Arguments

### Options
Add one or more of these to enable a certain setting

`-h` `--help`: Show the help screen

`-q` `--quiet`: Surpress output

`-l` `--log`: Log output to a file

`-c` `--capture-post`: Logs the POST data sent to `POST_log.txt`

### Configuration

`-p` `--port`: Listen on a specific port number.  Default is `80`.

`-w` `--webroot`: Sets the webroot for the server.  Files in this directory will be accessable.  Default is your current directory.

`-d` `--domain-name`: Only listens when requests are for a specific domain name.  Default is `0.0.0.0`, which allows all.


## Usage

QServe is meant for _quickly_ setting up a server.  For a more permanant solution, look elsewhere.  Benefits of qserve is how lightweight and small the binary is (290kb), while being a single file.  This is most useful for quickly sharing files, setting up a test server, and a multitude of lightweight webhosting activities.  [This](https://mehsecurity.org/phish) sample uses it for quickly setting up a phishing page, you can use it however you wish.

_sample usage with PM2 hosting multiple servers at once_
![](https://i.imgur.com/fELCgDi.png)

_pretty colors_
![](https://i.imgur.com/VRX4yaI.png)