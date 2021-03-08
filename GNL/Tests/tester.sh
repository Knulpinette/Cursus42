#!bin/bash

pwd=`pwd`
echo "Downloading files:"
[ -d 42cursus_gnl_tests ] || git clone https://github.com/mrjvs/42cursus_gnl_tests.git
[ -d get-next-line-testing-tools ] || git clone https://github.com/TinfoilPancakes/get-next-line-testing-tools.git
[ -d 42TESTERS-GNL ] || git clone https://github.com/Mazoise/42TESTERS-GNL.git
echo "Download complete."

echo "Running tests:"
cd $pwd/42cursus_gnl_tests
if [ ! -f ".altered" ]; then
	sed -i.tmp 's/.\/get_next_line/../'  Makefile && rm Makefile.tmp
	sed -i.tmp '12 s/\.\//sh &/' Makefile && rm Makefile.tmp
	sed -i.tmp '16 s/\.\//sh &/' Makefile && rm Makefile.tmp
	sed -i.tmp '52 s/\.\//sh &/' compile_and_run.sh && rm compile_and_run.sh.tmp
	sed -i.tmp '60 s/\.\//sh &/' compile_and_run.sh && rm compile_and_run.sh.tmp
	touch .altered
fi
make
sleep 2

make bonus
echo -e '\033[0m'
cd $pwd/get-next-line-testing-tools
if [ ! -f ".altered" ]; then
	sed -i.tmp 's/GNL_SOURCE_DIR = ..\/get_next_line/GNL_SOURCE_DIR = ../' Makefile && rm Makefile.tmp
	sed -i.tmp '10 s/^/	char	t[11];/' moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c && rm moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c.tmp
	sed -i.tmp 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c && moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c.tmp
	sed -i.tmp '12 s/^/	char	t[11];/' moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c && moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c.tmp
	sed -i.tmp 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c && moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c.tmp
	sed -i.tmp 's/..\/..\/..\/..\/get_next_line/..\/..\/..\/../' moulitest_files/testframework/v3/Makefile && moulitest_files/testframework/v3/Makefile.tmp
	touch .altered
fi
make mtest_all

echo -e '\033[0m'

cd $pwd/42TESTERS-GNL
bash ./all_tests_with_bonus.sh