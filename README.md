# MEMUSE
Command to show usage of memory on the whole system and on each process, including:
- Memory usage
- Swap usage
- Total cache
- Minor and major page faults

## BUILD:
```shell
$ make
```

## RUN:

```shell
$ ./memuse
```

## EXAMPLE OUTPUT:

```shell
$ ./memuse
##### System Memory #####
Total Mem.:	8090692kB
Free Mem.:	4559404kB
Total Swap:	4880380kB
Free Swap:	4880380kB
Cache size:	3072KB
#########################
MJFLT: Major page faults;
MNFLT: Minor page faults;
PID   NAME      MEMORY(MB)  SWAP USE  MJFLT MNFLT
1     systemd   2.148       0kB       44    11212
...   ...       ...         ...       ...   ...
2734  atom      61.840      0kB       2     27522
3089  vlc       20.703      0kB       473   71163
3318  atom      120.305     0kB       3     347798
3360  atom      61.246      0kB       0     26628
3481  chrome    39.359      0kB       0     48454
3752  bash      2.750       0kB       0     3827
```
