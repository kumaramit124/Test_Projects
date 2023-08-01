# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra

# Directory structure
SRCDIR = src
INCDIR = include
BUILDDIR = build
LIBDIR = lib

# Target executable
TARGET = myplat

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Library files
STATICLIB = $(LIBDIR)/libplat.a
DYNAMICLIB = $(LIBDIR)/libplat.so

# Compile and build rules
all: $(TARGET)

$(TARGET): $(OBJS) $(STATICLIB) $(DYNAMICLIB)
	$(CC) $(CFLAGS) -I$(INCDIR) -L$(LIBDIR) $< -o $@ -lplat

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Static library rules
$(STATICLIB): $(OBJS)
	ar rcs $@ $^

# Dynamic library rules
$(DYNAMICLIB): $(OBJS)
	$(CC) $(CFLAGS) -shared $^ -o $@

clean:
	rm -rf $(BUILDDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so $(TARGET)

