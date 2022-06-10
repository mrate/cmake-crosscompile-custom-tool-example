$ndk="${env:ANDROID_NDK_HOME}"
$platform="26"
$arch="arm64-v8a"
$path="build_android"

Remove-Item -Recurse -Confirm:$false -Force -Path ${path}

if (!(test-path ${path})) {
    mkdir ${path}
    Push-Location ${path}
    cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE="${ndk}/build/cmake/android.toolchain.cmake" -DANDROID_NDK="${ndk}" -DANDROID_PLATFORM="${platform}" -DANDROID_ABI="${arch}" ..
    Pop-Location
}

Push-Location ${path}
cmake --build .
Pop-Location