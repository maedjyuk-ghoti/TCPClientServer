CC=clang++
CXX=clang++
RM=rm -f
CPPFLAGS=-I/usr/local/opt/openssl/include
LDFLAGS=-L/usr/local/opt/openssl/lib -lssl -lcrypto

SRCS=driver.cpp client.cpp server.cpp ssl_client.cpp ssl_server.cpp
OBJS=$(SRCS:.cpp=.o)

SSLEXES=$(addprefix ssl_,$(EXES))

all: driver

driver: $(OBJS)
	$(CXX) $(LDFLAGS) -o driver $(OBJS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
