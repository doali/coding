# ------------------------------------------------------------------------------
# https://bugzilla.redhat.com/show_bug.cgi?id=172231
# - dbus-launch command belongs to package dbus-x11
# ------------------------------------------------------------------------------

FROM ubuntu:latest

ARG UID
ENV UID=${UID:-1000}

ARG PASSWORD
ENV PASSWORD=${PASSWORD:-ubuntu}

LABEL maintener="doali"

RUN apt-get update && apt-get install -y \
  iproute2 \
  iputils-ping \
  curl \
  build-essential \
  sudo \
  openssh-server \
  vim \
  git \
  python3-pip \
  libdbus-1-dev \
  libdbus-glib-1-dev \
  dbus-x11 # IMPORTANT !!

RUN pip install dbus-python

VOLUME /volume/data
EXPOSE 22

RUN useradd -rm -d /home/ubuntu -s /bin/bash -G sudo -u ${UID} ubuntu \
  && echo "ubuntu:${PASSWORD}" | chpasswd

COPY id_rsa.pub /tmp
RUN mkdir -p /home/ubuntu/.ssh \
  && mv /tmp/id_rsa.pub /home/ubuntu/.ssh/authorized_keys
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers # TODO find a better solution to run sshd...

USER ubuntu

RUN mkdir -p /home/ubuntu/.local/bin
ENV PATH=${PATH}:/home/ubuntu/.local/bin
COPY --chown=${UID} script.sh /home/ubuntu/.local/bin
RUN chmod u+x /home/ubuntu/.local/bin/script.sh

WORKDIR /home/ubuntu

ENTRYPOINT ["script.sh"]
CMD ["/bin/bash"]
