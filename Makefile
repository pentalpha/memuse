all:
	g++ --std=c++11	main.cpp Utils.cpp ProcInfo.cpp SysInfo.cpp -o memuse
	chmod +x memuse
