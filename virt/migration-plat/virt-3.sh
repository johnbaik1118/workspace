virt-install \
--name vmthree \
--ram 1024 \
--disk path=./vmthree.qcow2,size=20 \
--vcpus 2 \
--os-type linux \
--location 'http://archive.ubuntu.com/ubuntu/dists/xenial/main/installer-amd64/'
