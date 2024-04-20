#!/bin/bash

exists()
{
    command -v "$1" > /dev/null 2>&1
}

if exists git; then
    echo 'Git is already installed'
    exit 0
fi

if exists apt-get; then
    # Debian
    sudo apt-get update
    sudo apt-get install -y git

elif exists yum; then
    # Redhat
    sudo yum install -y git

elif exists pacman; then
    # Archlinux
    sudo pacman -Sy --noconfirm git

elif exists apk; then
    # Alpine
    sudo apk add --update git

elif exists dnf; then
    # Fedora
    sudo dnf install -y git

elif exists zypper; then
    # OpenSUSE
    sudo zypper install -y git

elif exists brew; then
    # MacOS with Homebrew
    brew install git

elif exists port; then
    # MacOS with MacPorts
    sudo port install git

elif exists pkg; then
    # FreeBSD
    sudo pkg install -y git

elif exists emerge; then
    # Gentoo
    sudo emerge --ask --noreplace dev-vcs/git

elif exists eopkg; then
    # Solus
    sudo eopkg install -y git

elif exists guix; then
    # Guix
    sudo guix package -i git

else
    echo 'Unsupported package manager, please install Git manually'
    exit 1
fi

if exists git; then
    echo 'Git was successfully installed'
    exit 0
else
    echo 'There was an error, please install Git manually'
    exit 1
fi

