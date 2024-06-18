#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc < 5)
    {
        printf("Usage: %s <intput file> <cut pos> <cut size> <output file>\n", argv[0]);
        return 0;
    }
    char *input_filename = argv[1];
    unsigned long pos = atoi(argv[2]);
    int cut_file_size = atoi(argv[3]);
    char *output_filename = argv[4];

    FILE *fpin = fopen(input_filename, "rb");
    char *buf = calloc(cut_file_size, 1);
    FILE *fpout = fopen(output_filename, "wb");
    if(!fpin || !buf || !fpout)
    {
        printf("open file error or alloc temp buffer failed! (error code: %d:%d:%d)\n", !fpin, !buf, !fpout);
        goto exit;
    }

    fseek(fpin, pos, SEEK_SET);
    int read_cnt = fread(buf, 1, cut_file_size, fpin);
    fwrite(buf, 1, read_cnt, fpout);

exit:
    if(fpin)
        fclose(fpin);
    if(fpout)
    {
        fflush(fpout);
        fclose(fpout);
    }
    if(buf)
        free(buf);
    return 0;
}
