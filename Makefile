CC=clang++
CXX=g++
RM=rm -f
CPPFLAGS=
LDFLAGS=

SRCS=driver.cpp client.cpp server.cpp
OBJS=$(SRCS:.cpp=.o)

SSLEXES=$(addprefix ssl_,$(EXES))

all: driver

driver: $(OBJS)
	$(CXX) $(LDFLAGS) -o driver $(OBJS) $(LDFLAGS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
