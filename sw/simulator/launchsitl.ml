#!/usr/bin/ocamlrun /usr/bin/ocaml
#load "unix.cma";;
let (//) = Filename.concat
let paparazzi_home =
  try
    Sys.getenv "PAPARAZZI_HOME"
  with
    _ -> Filename.concat (Sys.getenv "HOME") "paparazzi"

let () =
  let n = Array.length Sys.argv in
  try
    let ac = Sys.argv.(1) in
    let com = paparazzi_home // "var" // ac // "sim/simsitl" in
    let args = Array.sub Sys.argv 1 (n-1) in
    args.(0) <- com;
    Unix.execv com  args
  with _ ->
    failwith "Usage: launchsitl <ac_name> <options>"
