#! /bin/bash

gitfiles=(.git .gitmodules .gitattributes)
tmp_dir="/tmp/$(uuidgen)"
repo_url=git@github.com:flavien-chenu/clcc.git

if [ -z "$1" ]; then
    echo "Usage: pull.sh <path>"
    exit 1
fi

echo "Pulling from remote repository"
git clone $repo_url $tmp_dir

if [ $? -ne 0 ]; then
    echo "Error: unable to clone the remote repository"
    exit 1
fi

echo "Removing git files"
for i in ${gitfiles[@]}; do
    rm -rf $tmp_dir/$i
done

## Are you sure to proceed?
if [ -d $1 ]; then
    echo -n "Are you sure to proceed? (y/n): "
    read proceed
    if [ "$proceed" != "y" ]; then
        echo "Aborted."
        rm -rf $tmp_dir
        exit 0
    fi
fi

## Clear current directory except current shell script
find $1 -maxdepth 1 ! -wholename $0 ! -name "." ! -name ".." -exec rm -rf {} \;
cp -r $tmp_dir/. $1
rm -rf $tmp_dir
echo "Done. Up to date."
