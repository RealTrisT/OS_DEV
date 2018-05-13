cd bootsector
	./compile.sh
cd ../kernel
	make kernel
	cp kernel ../storage/KERNEL.bin
cd ../storage
	./concat.sh
	read
	./run.sh