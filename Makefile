dir=./data
file=6.in
files=5.in 6.in 7.in 15.in 24.in
runningfile=${dir}/${file}
allout=dpmin.out dp.out dfs.out dfsb.out bfs.out bfsq.out
name=$(allout:%.out=%)

compileall: dp.out dfs.out bfs.out bfsq.out dpmin.out

run: ${allout}
	@echo "[[[[[[[[[ BASIC MODE ]]]]]]]]]"
	@for va in ${name};do\
		echo ">>>>>>>>>>>>>>> $$va <<<<<<<<<<<<"; \
		./$$va.out < ${runningfile}; \
		echo "";\
	done

forrun: ${allout}
	@echo "[[[[ FOR MODE ]]]]"
	@for va in ${name};do\
		echo ">>>>>>>>>>>>>> $$va <<<<<<<<<<";\
		for f in ${files};do\
			echo "file=$$f";\
			./$$va.out < ${dir}/$$f;\
			echo "";\
		done;\
		echo "";\
	done

dfs: dfsb.out dfs.out
	./dfsb.out < ${runningfile}
	./dfs.out < ${runningfile}

bfs: bfsq.out bfs.out
	./bfsq.out < ${runningfile}
	./bfs.out < ${runningfile}

dp.out:
	@g++ -o dp.out dp.cpp

dfs.out:
	@g++ -o dfs.out dfs.cpp

bfs.out:
	@g++ -o bfs.out bfs.cpp

bfsq.out:
	@g++ -o bfsq.out bfsq.cpp

dpmin.out:
	@g++ -o dpmin.out dpmin.cpp

dfsb.out:
	@g++ -o dfsb.out dfsb.cpp

clean:
	rm -f *.out *.o
