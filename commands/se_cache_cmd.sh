#!usr/bin/env bash

./build/X86/gem5.opt \
		configs/example/se.py \
		--caches \
		--l1i_size=32kB \
		--l1d_size=32kB \
		--l1i_assoc=2 \
		--l1d_assoc=2 \
		--sys-clock=2GHz \
		--cpu-clock=2GHz \
		--mem-type=DDR4_2400_8x8 \
		--mem-size=2GB \
		--cmd=/home/vagrant/gem5-experiments/benchmarks/STREAM-master/stream_c.exe

