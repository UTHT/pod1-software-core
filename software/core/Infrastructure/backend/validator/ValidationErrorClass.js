class ValidationError extends Error {
    constructor(message) {
      super(message);
      this.name = "ValidationError";
    }
  }

//connect to json file with all errors
//string formatting

  module.exports = ValidationError