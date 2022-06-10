$path="build_host"

Remove-Item -Recurse -Confirm:$false -Force -Path ${path}

if (!(test-path ${path})) {
    mkdir ${path}
    Push-Location ${path}
    cmake ..
    Pop-Location
}

Push-Location ${path}
cmake --build .
Pop-Location