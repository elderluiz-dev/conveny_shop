# ==========================================
# Compiler and Flags Definitions
# ==========================================
CC        := gcc
TARGET    := run

# Mapeia as novas pastas de include de cada módulo e a pasta src
CFLAGS    := -Wall -Wextra -g \
             -Isrc \
             -Icircular/include \
             -Idupla/include \
             -Iinterface/include \
             -Iproduto/include \
             -Isimples/include

# ==========================================
# Directory Settings
# ==========================================
OBJDIR    := obj

# ==========================================
# Automatic File Discovery
# ==========================================
# Busca os arquivos .c na pasta src e em cada um dos módulos
SRCS      := $(wildcard src/*.c) \
             $(wildcard circular/*.c) \
             $(wildcard dupla/*.c) \
             $(wildcard interface/*.c) \
             $(wildcard produto/*.c) \
             $(wildcard simples/*.c)

# Gera a lista de arquivos .o dentro da pasta obj/
OBJS      := $(patsubst %, $(OBJDIR)/%, $(notdir $(SRCS:.c=.o)))

# ==========================================
# Build Rules
# ==========================================

# Define os caminhos onde o Make deve procurar os arquivos .c
vpath %.c src circular dupla interface produto simples

# Alvo padrão
all: $(TARGET)

# Cria o executável final linkando todos os objetos do obj/
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os .c em .o
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET)
