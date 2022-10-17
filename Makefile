CXX=g++
CXXFLAGS=-c -pedantic -Wall -Wextra -Wshadow -Wconversion -Wunreachable-code -std=c++17
LDFLAGS=-lm

TMPEXECUTABLE=SmartCalc2.app/Contents/MacOS/SmartCalc2

MODELCPP=$(wildcard model/*.cpp)
MODELOBJ=$(MODELCPP:.cpp=.o)
LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report
EXECUTABLE=SmartCalc2
EXECUTABLE_TEST=tests

INSTALLDIR=../build
BUILDDIR=SmartCalc

.PHONY: all build test gcov_report style clean leaks rebuild

all: build
#/opt/Qt/6.3.1/gcc_64/bin/qmake
build:
	mkdir $(BUILDDIR)
	cp SmartCalc2.pro $(BUILDDIR)
	cd $(BUILDDIR) && qmake SmartCalc2.pro && make
	cp $(BUILDDIR)/$(TMPEXECUTABLE) $(EXECUTABLE)

install: all
	mkdir $(INSTALLDIR)
	cp $(EXECUTABLE) $(INSTALLDIR)/$(EXECUTABLE)

uninstall:
	rm -rf $(INSTALLDIR)

dist: build 
	mkdir smart_calc-1.00
	cp $(EXECUTABLE) smart_calc-1.00/$(EXECUTABLE)
	tar --totals -cvf smart_calc-1.00.tar smart_calc-1.00
	gzip smart_calc-1.00.tar
	rm -rf smart_calc-1.00

dvi: info.dvi

info.dvi: info/d5e0e1e06faa4af1808a749c2cc755f6.texi
	texi2dvi info/d5e0e1e06faa4af1808a749c2cc755f6.texi


build_tests: LDFLAGS+=-lgtest
build_tests: test.o $(MODELOBJ)
	$(CXX) $^ -o $(EXECUTABLE_TEST) $(LDFLAGS) -pthread

tests: build_tests
	./$(EXECUTABLE_TEST)

gcov_report: CXXFLAGS+=--coverage
gcov_report: LDFLAGS+=--coverage
gcov_report: tests
	lcov -t $(EXECUTABLE) -o $(LCOVEXEC) -c -d .
	lcov -r $(LCOVEXEC) "/usr*" -o $(LCOVEXEC)
	genhtml -o $(REPORTDIR) $(LCOVEXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

style:
	cppcheck --std=c++17 --language=c++ --enable=all --suppressions-list=suppressions.txt ./
	python3 ../materials/linters/cpplint.py --filter=-runtime/references --extensions=cpp,h --recursive --exclude=qcustomplot.cpp --exclude=qcustomplot.h . 

leaks: build_tests
	CK_FORK=no valgrind -s --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE_TEST)

clean:
	rm -rf *.o *.out $(EXECUTABLE) $(EXECUTABLE_TEST) SmartCalc2 $(BUILDDIR)
	rm -rf model/*.o smart_calc-1.00.tar.gz model/*.gcno model/*.gcda model/*.gcov
	rm -rf *.gcno *.gcda *.gcov $(LCOVEXEC) $(REPORTDIR)

rebuild: clean all
