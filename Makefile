# Name: David Thuita modded from class
#
STD=-std=c++11
OPT=-g
FLAGS=
CXXFLAGS=${STD} ${OPT} $(FLAGS)
CFLAGS=${OPT}

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%.o: %.cxx
	$(CXX) -c $(CXXFLAGS) $<

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

%: %.c
	$(CC) -o $@ $(CFLAGS) $<

%: %.cxx
	$(CXX) -o $@ $(CXXFLAGS) $<

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

TMPMAKE=tmpMake

HEADERS=scuclass.h
LLSRCS=scuclass.cxx student.cxx test_functions.cxx main_test.cxx
LLOBJS=$(LLSRCS:.cxx=.o)

ALLSRCS= $(LLSRCS)
ALLOBJS= $(ALLSRCS:.cxx=.o)
ALL= scuclass

all:	$(ALL)	

test:	$(LLOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

tar:
	tar cf linkedlist.tar $(LLSRCS) linkedlist.h node.h scuclass.test Makefile
clean:
	/bin/rm -f $(ALL) $(ALLOBJS) linkedlist.tar

depend: $(ALLSRCS)
	/bin/rm -f $(TMPMAKE)
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $(TMPMAKE)
	echo '# DEPENDENTS' >> $(TMPMAKE)
	$(CXX) -MM $+ >> $(TMPMAKE)
	/bin/mv -f $(TMPMAKE) Makefile

# DEPENDENTS
scuclass.o: scuclass.cxx student.cxx scuclass.h
test.o: main_test.cxx test_functions.cxx scuclass.cxx student.cxx scuclass.h
