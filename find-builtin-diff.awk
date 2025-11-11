{
name[FNR]=$1;
name1[FNR]=$3;
size[NR]=$4;
}
END{
for(i=1;i<=FNR;i++)
{
diff=size[i]-size[FNR+i];
if(diff) {
printf("%66s withoutB: %5d withB: %5d size-diff: %4d ratio-diff: %.2f%%\n",name1[i],size[i],size[FNR+i],diff, diff*100/size[i]);
}
}
}
