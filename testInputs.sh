# Execute este arquivo para testar os inputs dentro da pasta inputs/
floyd=./floyd_warshall.bin

make clean;
make;

echo "Testando algoritmo de Floyd"
for i in inputs/*.dat
do
	echo -e "\e[33mInstância $i salva em outputs/$filename\e[0m";

    filename=$(basename "$i")
	$floyd -f $i -o outputs/$filename;
done