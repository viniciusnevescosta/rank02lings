#!/usr/bin/env python3
"""Check manifests and ensure every shipped exercise initially fails."""
from pathlib import Path
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import tester


def main():
    entries = [e for e in tester.ALL if not e['id'].startswith('s0')]
    if len(entries) != 80 or len({e['id'] for e in entries}) != 80:
        raise SystemExit('Expected 80 distinct starter exercises.')
    unexpected = []
    for entry in entries:
        source = tester.ROOT / entry['path'] / (entry['id'] + '.c')
        if not source.is_file():
            raise SystemExit(f'Missing source: {source}')
        ok, message = tester.run(entry)
        if ok or message.startswith('FERRAMENTAS/ARQUIVOS'):
            unexpected.append((entry['id'], message))
        print(f"{'UNEXPECTED' if ok else 'EXPECTED FAIL'} {entry['id']}", flush=True)
    if unexpected:
        for identifier, message in unexpected:
            print(identifier, message)
        return 1
    print('All 80 starter exercises are rejected, as intended.')
    return 0


if __name__ == '__main__':
    sys.exit(main())
