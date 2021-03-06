#!/bin/bash

#current path
PROJECT_DIR=`pwd`

#version
VERSION=1.0.0

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
    
    echo "Copy files..."
    
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/bin
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/log
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/lib
    mkdir -p $PROJECT_DIR/InstallPackage/SMSSrv/etc
    
    if [ $(ls $PROJECT_DIR/bin/ | wc -l) -gt 0 ] 
    then
        cp -R $PROJECT_DIR/bin/*     $PROJECT_DIR/InstallPackage/SMSSrv/bin/
    fi

    if [ $(ls $PROJECT_DIR/lib/ | wc -l) -gt 0 ]
    then
        cp -R $PROJECT_DIR/lib/*     $PROJECT_DIR/InstallPackage/SMSSrv/lib/
    fi
    
    if [ $(ls $PROJECT_DIR/lib_dep/ | wc -l) -gt 0 ] 
    then
        cp -R $PROJECT_DIR/lib_dep/*	$PROJECT_DIR/InstallPackage/SMSSrv/lib/
    fi

    if [ $(ls $PROJECT_DIR/etc/ | wc -l) -gt 0 ]
    then 
        cp -R $PROJECT_DIR/etc/*     $PROJECT_DIR/InstallPackage/SMSSrv/etc/
    fi

    rm -fr $PROJECT_DIR/InstallPackage/SMSSrv/lib/*.a
    
    
    find $PROJECT_DIR/InstallPackage/ -type d -name ".svn" | xargs rm -rf
       
    echo "Generate software install package..."
    cd $PROJECT_DIR/InstallPackage/
    
    tar -zcf SMSSrv_$VERSION\_`date +%Y%m%d`.tar.gz SMSSrv
    
    rm -fr SMSSrv
    
    echo "Generate software install package finish."
}

make_project()
{
    cd $PROJECT_DIR/build
    
    cmake ..
    
    make
}

make_clean()
{
    echo "Remove project temporary files."
	
    cd lib			   
    
    rm -fr `ls . | grep -v extends | grep -v oracle | grep -v log`
    rm -fr $PROJECT_DIR/bin/* 2>/dev/null

    CLEAN_DIR=$PROJECT_DIR
		
    if [ -d $CLEAN_DIR/lib ] && [ -d $CLEAN_DIR/bin ] && [ -d $CLEAN_DIR/build ]
    then
        rm $CLEAN_DIR/lib/* 2>/dev/null
        rm $CLEAN_DIR/bin/* 2>/dev/null
        rm -r $CLEAN_DIR/build/* 2>/dev/null
    fi
    
    echo "clean finish."
}


if [ $# -gt 0 ] 
then

	if [ "$1" = "help" ] 
	then
		usage
	fi
	
	if [ "$1" = "all" ] 
	then
		make_project
	fi
	
	if [ "$1" = "clean" ] 
	then
		make_clean
	fi
	
	if [ "$1" = "dist" ] 
	then
		make_dist
	fi
else
    make_project
fi

exit
