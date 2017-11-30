sudo qemu-img create -f qcow2 vm-one.img 16G
sudo qemu-system-x86_64 -hda vm-one.img -cdrom ~/Downloads/ubuntu-16.04.3-desktop-amd64.iso -boot d -m 1024
