const md5 = require("md5-file").sync;
const path = require("path");
const native = require("../src/native");

const filePath = path.join(__dirname, "./test-file.txt");

describe("filehash", () => {
    describe("md5-file", () => {
        it("should compute the hash", () => {
            for (let i = 0; i < 10000; i++) {
                expect(md5(filePath)).toEqual("090b4a3b531c0d02a4f49b42fa733ade");
            }
        });
    });

    describe("native", () => {
        it("should compute the hash", () => {
            for (let i = 0; i < 10000; i++) {
                expect(native.md5Hash(filePath)).toBe("090b4a3b531c0d02a4f49b42fa733ade");
            }
        });
    });
});
