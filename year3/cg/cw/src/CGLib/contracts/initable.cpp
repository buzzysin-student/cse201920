#pragma once

class WindowWrapper;

class Initable
{
protected:
  // ? Call when starting operation
  virtual void init() = 0;
public:
  class WithWrapper {
    public: 
      virtual void init(WindowWrapper wrapper) = 0;
  };
};