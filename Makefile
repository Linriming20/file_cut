file_cut: file_cut.c
	gcc $^ -o $@
clean:
	rm -rf file_cut
