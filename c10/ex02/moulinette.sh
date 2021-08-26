#/bin/sh
echo "TEST 0:"
./ft_tail -c 10 test > m1
tail -c 10 test > m2
diff m1 m2

echo "TEST 1:"
./ft_tail -c 10 test test > m1 
tail -c 10 test test > m2
diff m1 m2

echo "TEST 2:"
./ft_tail -c 10 test_s_3 > m1
tail -c 10 test_s_3 > m2
diff m1 m2

echo "TEST 3:"
./ft_tail -c 10 test_s_3 test > m1 
tail -c 10 test_s_3 test > m2
diff m1 m2

echo "TEST 4:"
./ft_tail -c 10 test_s_3 unexistant_file > m1
tail -c 10 test_s_3 unexistant_file > m2
diff m1 m2

echo "TEST 5:"
./ft_tail -c 10 unexistant_file > m1 
tail -c 10 unexistant_file > m2
diff m1 m2

echo "TEST 6:"
./ft_tail -c10 test > m1
tail -c10 test > m2
diff m1 m2

echo "TEST 7:"
./ft_tail -cbruh_offset test > m1
tail -cbruh_offset test > m2
diff m1 m2

echo "TEST 8:"
./ft_tail -c bruh_offset test > m1
tail -c bruh_offset test > m2
diff m1 m2

echo "TEST 9:"
./ft_tail -c 10 unexistant_file test > m1
tail -c 10 unexistant_file test > m2
diff m1 m2

echo "TEST 10:"
./ft_tail -c 10 unexistant_file unexistant_file > m1
tail -c 10 unexistant_file unexistant_file > m2
diff m1 m2

echo "TEST 11:"
./ft_tail -c 10 unexistant_file test unexistant_file > m1
tail -c 10 unexistant_file test unexistant_file > m2
diff m1 m2

echo "TEST 12:"
./ft_tail -c 10 test unexistant_file unexistant_file > m1
tail -c 10 test unexistant_file unexistant_file > m2
diff m1 m2

echo "TEST 13:"
./ft_tail -c 10 test unexistant_file test_s_3 test unexistant_file > m1
tail -c 10 test unexistant_file test_s_3 test unexistant_file > m2
diff m1 m2

echo "TEST 14:"
./ft_tail -c > m1
tail -c > m2
diff m1 m2
