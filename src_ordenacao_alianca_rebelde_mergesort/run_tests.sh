EXEC=$1
TMP_OUT=$2

echo "Aliança Rebelde - Merge Sort"

for i in {0..9..1}; do
  start=`date +%s`
  testname=$(printf "%01d" $i)
  $EXEC < ../tests/$testname.in > $TMP_OUT
  end=`date +%s`
  runtime=$((end-start))
  if ! diff -qwB ../tests/$testname.out $TMP_OUT &>/dev/null; then

    echo "Test $testname finish - Tempo de execução: $runtime (segundos) - Status: failed"
  else

    echo "Test $testname finish - Tempo de execução: $runtime (segundos) - Status: passed"
  fi
done