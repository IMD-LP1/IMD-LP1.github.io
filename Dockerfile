FROM ubuntu:16.04
MAINTEINER imd-lp1.github.io
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y htop wget nano vim less zip
RUN apt-get install -y perl gcc default-jre default-jdk apt-utils
RUN apt-get install -y make python-pip
RUN apt-get install -y python-tk
RUN pip install --upgrade pip

RUN apt-get install build-essential

RUN apt-get install doxygen-gui
RUN apt-get install graphviz

#######################
# INSTALL APACH
#######################
RUN apt-get install -y apache2 openssh 
# Pacote que contem o programa para gerar o passwd
RUN apt-get install -y whois
# Criando usuario e dando permissão
RUN useradd -m Heisenberg
RUN mkpasswd Heisenberg > /home/Heisenberg/senha.txt
RUN usermod -a -G sudo Heisenberg
RUN chsh -s /bin/bash Heisenberg

# Criando pasta public_html
RUN mkdir /home/Heisenberg/public_html
RUN chown Heisenberg /home/Heisenberg/public_html
RUN chgrp Heisenberg /home/Heisenberg/public_html
WORKDIR /etc/apache2/mods-enabled/

RUN ln -s ../mods-available/userdir.conf
RUN ln -s ../mods-available/userdir.load
# Ver configuraçẽos de IP para o apache
RUN /etc/init.d/apache2 start > /home/Heisenberg/ip.txt
RUN mkdir /home/Heisenberg/public_html/Genoma
RUN mv /home/senha.txt /home/Heisenberg/

WORKDIR /root

RUN apt-get clean
