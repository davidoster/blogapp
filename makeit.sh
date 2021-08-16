clear
cd views
make qmake
cd ..
qmake -r "CONFIG+=$1"
make
echo "Running..."
treefrog -e dev
