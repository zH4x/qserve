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