CXXFLAGS=-Wall -O3 -g
LLNW_OBJECTS= \
    src/llnw-led.o
LLNW_BINARY=llnw-led
LLNW_BIN_LOCATION=/opt/llnw/bin
LLNW_SCRIPTS=python/getjson.py


# Where our library resides. It is split between includes and the binary
# library in lib
RGB_INCDIR=include
RGB_LIBDIR=lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a
LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread

all: $(LLNW_BINARY)

$(RGB_LIBRARY):
	$(MAKE) -C $(RGB_LIBDIR)


$(LLNW_BINARY): $(LLNW_OBJECTS) $(RGB_LIBRARY)
	$(CXX) $(CXXFLAGS) $(LLNW_OBJECTS) -o $@ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(LLNW_OBJECTS) $(LLNW_BINARY)
	$(MAKE) -C lib clean

install: $(LLNW_BINARY)
	@echo "Compiling and installing binary to $(LLNW_BIN_LOCATION) ###MUST BE RUN AS ROOT###"
	install -D $(LLNW_BINARY) $(LLNW_BIN_LOCATION)/$(LLNW_BINARY)
	cp -f $(LLNW_SCRIPTS) $(LLNW_BIN_LOCATION)

