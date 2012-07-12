#!/bin/bash

#current path
PROJECT_DIR=`pwd`

usage()
{
    printf "Usage of make.sh:\n"
    printf "\t clean        : clean the all builded files\n"
    printf "\t all          : make all the subproject\n"
    printf "\t dist         : distribution software package \n"
    printf "\t help         : list the option\n"
    
    echo
}

make_dist()
{
    echo 
    echo "============================================================"
    echo
    echo "          Generate SMS Software Install Package             "
    echo 
    echo "============================================================"
    echo
    
    echo "Copy File..."
    
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/bin
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/log
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/lib
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/etc
    
    cp -R $PROJECT_DIR/bin/*     $PROJECT_DIR/InstallPackage/SMSSrv/bin/ 
    cp -R $PROJECT_DIR/lib_dep/* $PROJECT_DIR/InstallPackage/SMSSrv/lib/
    cp -R $PROJECT_DIR/etc/*     $PROJECT_DIR/InstallPackage/SMSSrv/etc/
    
    rm -fr $PROJECT_DIR/InstallPackage/SMSSrv/lib/*.a
    
    
    find $PROJECT_DIR/InstallPackage/ -type d -name ".svn" | xargs rm -rf
       
    echo "Generate Install Package..."
    cd $PROJECT_DIR/InstallPackage/
    
    tar -zcf SMSSrv_1.0.0.tar.gz SMSSrv
    
    rm -fr SMSSrv
    
    echo "Generate Install Package Finish."
}


if [ $# -gt 0 ] 
then

	if [ "$1" = "help" ] 
	then
		usage
	fi
	
	if [ "$1" = "dist" ] 
	then
		make_dist
	fi
fi

exit
