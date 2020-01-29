import { terser } from 'rollup-plugin-terser';
import resolve from 'rollup-plugin-node-resolve';
import rimraf from 'rimraf';

rimraf.sync('./main-x.js');
const extensions = ['.js', '.jsx', '.ts', '.tsx'];
export default {
  input: './main-c.js',
  output: {
    file: 'main-x.js',
    format: 'cjs'
  },
  plugins: [
    resolve({ extensions }),
    terser({
      output: {
        comments: () => false
      }
    })
  ]
};
