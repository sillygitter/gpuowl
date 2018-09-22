// gpuOwL, a GPU OpenCL Lucas-Lehmer primality checker.
// Copyright (C) 2017-2018 Mihai Preda.

#pragma once

#include "common.h"
#include <string>
#include <memory>

class Args;
class Result;

struct Task {
  enum Kind {NONE = 0, TF, PM1, PRP};

  Kind kind;
  u32 exponent;
  string AID;  
  string line; // the verbatim worktodo line, used in deleteTask().

  // TF & PRP (PRP tasks may contain "factored up to" bitlevel).
  u32 bitLo;
  
  // TF only
  u32 bitHi;

  // PM1 only.
  // u32 B1;

  operator bool() { return kind != NONE; }

  // A different task may need to be done beforehand.
  Task morph(Args *args);

  unique_ptr<Result> execute(const Args &args);
};
