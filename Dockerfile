# Usa uma imagem base do Ubuntu
FROM ubuntu:latest

# Instala as ferramentas de compilação para C (por exemplo, gcc)
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Define o diretório de trabalho no contêiner
WORKDIR /philo

# Copia todos os arquivos para o diretório de trabalho
COPY . .

# Compila o código
RUN cc -Wall -Wextra -Werror -pthread -o philo \
    philo.c src/utils.c src/init.c src/threads.c src/actions.c src/print_routine.c

# Comando padrão ao iniciar o contêiner
CMD [ "./philo", "2", "800", "200", "300" ]
